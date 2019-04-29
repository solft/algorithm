from itertools import combinations
from functools import reduce

data = [
    [1, 2, 3, 4],
    [1, 2, 4],
    [1, 2],
    [2, 3, 4],
    [2, 3],
    [3, 4],
    [2, 4]
]

attributes_counter = {}
attributes = []

# 데이터 초기 분석
for item in data:
    for attr in item:
        if attr in attributes_counter.keys():
            attributes_counter[attr] += 1
        else:
            attributes.append({attr})
            attributes_counter[attr] = 1

print(attributes_counter)
print(attributes)


# self_join 하는 함수
def self_join(set_list, size):
    tuple_list = combinations(set_list, size)
    result = []
    for tup in tuple_list:
        result.append(reduce(lambda x, y: x | y, tup))
    return result


test1 = self_join(attributes, 2)
print(test1)

test2 = self_join(test1, 2)
print(test2)


# # Self join
# # 길이가 2짜리인 subset 을 구하고 (tuple 들로 리턴)
# test1 = combinations(attributes, 2)
# test2 = []
# for i in test1:
#     temp = reduce(lambda x, y: x | y, i)
#     print(temp)
#     test2.append(temp)
#
# print(test2)
# # # set 리스트로 만들기
# # test2 = []
# # for i in test1:
# #     test2.append(set(i))
# # print(test2)



