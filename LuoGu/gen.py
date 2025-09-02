from cyaron import *
import random
import os
cnt = 3000
n = 1000
m = 1000
P = "p2105"
xxxx = [i for i in range(1, m + 1)]
yyyy = [i for i in range(1, n + 1)]
os.system("g++ -O2 -std=c++20 -Wall " + P + "_.cpp -o " + P + "_.exe")
os.system("g++ -O2 -std=c++20 -Wall " + P + ".cpp -o " + P + ".exe")
while cnt > 0:
    in_ = IO(input_file="www.in")
    out_ = IO(output_file=P+"_.out", input_file="www.in")
    out__ = IO(output_file=P+".out", input_file="www.in")
    k = randint(300, 500)
    in_.input_writeln(n, m, k)
    xxx = random.sample(xxxx, k)
    yyy = random.sample(yyyy, k)
    for _ in range(k):
        in_.input_writeln(xxx[_], yyy[_])
    # Compare.program("p1127.exe", input=in_, std_program="p1127_.exe")
    out_.output_gen(P+"_.exe")
    out__.output_gen(P+".exe")
    Compare.output(P+".out", std=P+"_.out")
    cnt -= 1
    print("cnt = ", cnt)