import numpy as np
import math
from pyqubo import Array, Constraint, Placeholder
from dwave.system import DWaveSampler, EmbeddingComposite
import pandas as pd
import time

start_time = time.perf_counter()

# token = "DEV-205dd894227404d65f9101e7383cafaa76e38268"
# token = "DEV-8c2524810d4476a92f06896ccc1356fe7b395c52"
# token = "DEV-22596067d96dc6c58ca6e3a12cc653011cb4bbaf"
# token = "DEV-e6e2d394bdcb40aed763894cf7ec2a714b89ca7c"
# token = "DEV-5d1fa16ae77dc89d7a856eed25f0a254a6fce9e1"
token = "DEV-e479f05871150f481f121df26ae16ad923fe45e0"



endpoint = "https://cloud.dwavesys.com/sapi/"
solver = "Advantage_system4.1"

t_notch = 5
theta_notch = 5
x_binary = Array.create("x_binary", shape=(t_notch, 8, theta_notch), vartype="BINARY")
# 時間制約
cost1 = 0
for i in range(t_notch):
    cost1 += (np.sum(x_binary[i][0]) - 1) ** 2
    cost1 += (np.sum(x_binary[i][1]) - 1) ** 2
    cost1 += (np.sum(x_binary[i][2]) - 1) ** 2

# 初期・目標条件
cost2 = 0
cost2 = (
    (x_binary[0][0][0] - 1) ** 2
    + (x_binary[0][0][1]) ** 2
    + (x_binary[0][0][2]) ** 2
    + (x_binary[0][0][3]) ** 2
    + (x_binary[0][0][4]) ** 2
    + (x_binary[0][1][0]-1) ** 2
    + (x_binary[0][1][1]) ** 2
    + (x_binary[0][1][2]) ** 2
    + (x_binary[0][1][3]) ** 2
    + (x_binary[0][1][4]) ** 2
    + (x_binary[0][2][0]) ** 2
    + (x_binary[0][2][1]) ** 2
    + (x_binary[0][2][2]) ** 2
    + (x_binary[0][2][3]) ** 2
    + (x_binary[0][2][4]-1) ** 2
    + (x_binary[4][0][0]) ** 2
    + (x_binary[4][0][1]) ** 2
    + (x_binary[4][0][2]) ** 2
    + (x_binary[4][0][3]-1) ** 2
    + (x_binary[4][0][4]) ** 2
    + (x_binary[4][1][0]) ** 2
    + (x_binary[4][1][1]) ** 2
    + (x_binary[4][1][2]) ** 2
    + (x_binary[4][1][3]-1) ** 2
    + (x_binary[4][1][4]) ** 2
    + (x_binary[4][2][0]) ** 2
    + (x_binary[4][2][1]) ** 2
    + (x_binary[4][2][2]-1) ** 2
    + (x_binary[4][2][3]) ** 2
    + (x_binary[4][2][4]) ** 2
)
cost3 = 0
for i in range(1, t_notch):
    for j in range(theta_notch):
        for k in range(theta_notch):
            cost3 += x_binary[i - 1][0][j] * x_binary[i][0][k] * ((j - k)*(j - k))
            cost3 += x_binary[i - 1][1][j] * x_binary[i][1][k] * ((j - k)*(j - k))
            cost3 += x_binary[i - 1][2][j] * x_binary[i][2][k] * ((j - k)*(j - k))

cost4 = 0
for i in range(t_notch):
    for j in range(theta_notch):
        cost4 += x_binary[i][0][0]*x_binary[i][1][j]-2*(x_binary[i][0][0]+x_binary[i][1][j])*x_binary[i][3][j]+3*x_binary[i][3][j]
        cost4 += x_binary[i][0][1]*x_binary[i][1][j]-2*(x_binary[i][0][1]+x_binary[i][1][j])*x_binary[i][4][j]+3*x_binary[i][4][j]
        cost4 += x_binary[i][0][2]*x_binary[i][1][j]-2*(x_binary[i][0][2]+x_binary[i][1][j])*x_binary[i][5][j]+3*x_binary[i][5][j]
        cost4 += x_binary[i][0][3]*x_binary[i][1][j]-2*(x_binary[i][0][3]+x_binary[i][1][j])*x_binary[i][6][j]+3*x_binary[i][6][j]
        cost4 += x_binary[i][0][4]*x_binary[i][1][j]-2*(x_binary[i][0][4]+x_binary[i][1][j])*x_binary[i][7][j]+3*x_binary[i][7][j]
    
cost5 = 0
for i in range(t_notch):
    cost5 += x_binary[i][5][0]*x_binary[i][2][0]+x_binary[i][5][0]*x_binary[i][2][1]+x_binary[i][5][0]*x_binary[i][2][2]+x_binary[i][5][0]*x_binary[i][2][3]+x_binary[i][5][0]*x_binary[i][2][4]
    cost5 += x_binary[i][6][0]*x_binary[i][2][0]+x_binary[i][6][0]*x_binary[i][2][1]+x_binary[i][6][0]*x_binary[i][2][2]+x_binary[i][6][0]*x_binary[i][2][3]+x_binary[i][6][0]*x_binary[i][2][4]
    cost5 += x_binary[i][5][1]*x_binary[i][2][0]+x_binary[i][5][1]*x_binary[i][2][1]+x_binary[i][5][1]*x_binary[i][2][2]+x_binary[i][5][1]*x_binary[i][2][3]+x_binary[i][5][1]*x_binary[i][2][4]
    cost5 += x_binary[i][5][0]*x_binary[i][2][0]+x_binary[i][5][0]*x_binary[i][2][1]+x_binary[i][5][0]*x_binary[i][2][2]+x_binary[i][5][0]*x_binary[i][2][3]+x_binary[i][5][0]*x_binary[i][2][4]
    cost5 += x_binary[i][5][2]*x_binary[i][2][2]+x_binary[i][5][2]*x_binary[i][2][3]
    cost5 += x_binary[i][6][2]*x_binary[i][2][2]+x_binary[i][6][2]*x_binary[i][2][3]

break1_time = time.perf_counter()
print("start of program to end of define : ",break1_time-start_time)
A = Placeholder("A")
B = Placeholder("B")
C = Placeholder("C")
D = Placeholder("D")
E = Placeholder("E")
cost_func = A * cost1 + B * cost2 + C * cost3 + D * cost4 + E * cost5
model = cost_func.compile()
feed_dict = {"A": 10.0, "B": 10.0, "C": 1.0, "D": 10.0, "E": 10.0}
qubo, offset = model.to_qubo(feed_dict=feed_dict)
break2_time = time.perf_counter()
print("end of define to define qubo : ",break2_time-break1_time)
for i in range(1):
    dw_sampler = DWaveSampler(solver=solver, token=token, endpoint=endpoint)
    break3_time = time.perf_counter()
    print("define qubo to define sampler : ",break3_time-break2_time)
    sampler = EmbeddingComposite(dw_sampler)
    break4_time = time.perf_counter()
    print("define sampler to mapping : ",break4_time-break3_time)
    sampleset = sampler.sample_qubo(
        qubo,
        num_reads=3000,
        # chain_strength=1500,
        annealing_time=80,
    )
    break5_time = time.perf_counter()
    print("mapping to anneal : ",break5_time-break4_time)
    print(sampleset.first)
    df = sampleset.to_pandas_dataframe()
    res = i+1
    title = "armresult"+str(res)+".csv"
    df.to_csv(title)
    # s = str(sampleset.first)
    # target = 'energy=-'
    # idx = s.find(target)
    # r = s[idx+8:idx+10]
    # print(r)
    # if int(r)>20:
    #     print(sampleset.first)
    #     break
end_time = time.perf_counter()
print("anneal to end of program : ",end_time-break5_time)
print("program time : ",end_time-start_time)
