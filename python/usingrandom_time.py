import time
import random
start_time=time.time()
random.seed(6)
for _ in range(5):
    print(random.randint(10,50))
end_time=time.time()
print("giving seed value as time of execution: ")
random.seed(start_time-end_time)
for _ in range(5):
    print(random.randint(10,50))