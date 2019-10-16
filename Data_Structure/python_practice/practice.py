

if __name__ == "__main__" :

    print(2)
    # 진수 변환
    print(0x1A) # 16진수을 1A을 10진수로 전환, 0o = 8, 0b = 2
    print(int("11", 16)) # 16진수 11을 10진수로 전환

    # join = 문자열을 합침
    jo = ','.join(['a','b','cde'])
    print("join ", jo)

    # format
    print("Name: {0}, Age: {1}: {0}의 나이가 {1}".format("민호", 17))

    # 중복 제거
    a = [1,2,3]
    c = a+b
    print(c)
    c = list(set(c))
    print(c)

    # 복사
    a = [[1, 2], [3, 4]]
    b = a[:]
    #  주의 : 재할당에는 문제가 없지만 a[1]을 변경하면 문제가 있다
    # a -> [[8, 9], [3, 4]]
    # b -> [[1, 2], [3, 4]]

    # a[1].append(5)
    # a -> [[8, 9], [3, 4, 5]]
    # b -> [[1, 2], [3, 4, 5]]

    #깊은 복사를 하자 : copy.deepcopy



    # 해당 리스트에서 원소가 나타내는 위치 찾는법
    a = ['서울', '인천', '대전', '제주도']
    print(a.index('인천'))
    print(a.count('서울'))
    bol = '서울' in a
    print(bol)

    # 삽입 : insert(a, b) = a의 위치에 b 삽입
    a = [1,2,3]
    a.insert(2,6)
    print(a)

    # 삭제 del a[1] : 1번째 원소 삭제 a.remove(2) : 원소가 2일 경우 삭제

    # sort
    a = ['서울', '인천', '대전', '제주도']
    a.sort(key = len) # len을 기준으로 sort
    print(a)

    #tuple

    #dictionaey
    #key로 tuple은 쓸 수 있는데 리스트, set은 못쓴다
    from pprint import pprint as pp
    pp(a) # 하면 딕셔너리가 보기 편하게 출력


    # set
    # 중복은 자동으로 제거된다.
    # 값 추가 = a.add(10), a.update([10,20,30])
    # 삭제 = a.remove(10), a.discard(10) : discard가 더 좋다 없어도 에러 안뜸ㅇㅇ
    # 복사 : b = set(a)
    # | : 합집합 연산자 -> c = a | b -> c = a.union(b)
    # & : 교집합 연산자 -> c = a & b -> c = a.intersection(b)
    # - : 차집합 연산자 -> c = a - b -> c = a.difference(b)
    # ^ : 대차집합 연산자(XOR) -> c = a ^ b -> c = a.symmetric_difference(b)

    # b가 a의 부분집합이냐?
    a = {1,2,3,4,5}
    b = {1,2,3}
    print(a.issubset(b))
    print(b.issubset(a))

    # b와 a가 교집합이 없냐 ?
    print(a.isdisjoint(b))

    # 반복문이 몇번째일까 ?
    t = [1, 5, 7, 33, 39, 52]
    for p in enumerate(t):
        print(p)

    for i, v in enumerate(t):
        print("index : {}, value: {}".format(i, v))



    # 예외처리
    def convert(s):
        try:
            a = int(s)
        except ValueError:
            a = -1
        return a

    a = convert("test")
    print(a)


    def convert(s):
        try:
            a = int(s)
            print('성공')
        except (ValueError, TypeError) as e:
            print('에러정보 : ', e)
            a = -1
        return a

    # generator :  iterator를 생성해주는 함수, 함수안에 yield 키워드를 사용함
    # yield : 호출되면 암시적으로 return이 호출되며, 한번 더 실행되면 실행되었던 `yield' 다음 코드가 실행됩니다.

    def test_generator():
        print('yield 1 전')
        yield 1
        print('yield 1과 2사이')
        yield 2
        print('yield 2와 3사이')
        yield 3
        print('yield 3 후')
    g = test_generator()
    next(g)
    next(g)