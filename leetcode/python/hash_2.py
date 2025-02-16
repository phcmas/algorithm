class HashTable:
    def __init__(self, size=10):
        self.size = size
        self.table = [None] * size  # 리스트로 해시 테이블 생성

    def _hash(self, barcode):
        """해시 함수: 바코드를 테이블 크기로 나눈 나머지"""
        return barcode % self.size

    def insert(self, barcode, quantity):
        """상품 바코드와 재고 수량을 저장"""
        index = self._hash(barcode)

        while self.table[index] is not None:
            if self.table[index][0] == barcode:  # 기존 값 업데이트
                self.table[index] = (barcode, quantity)
                return
            index = (index + 1) % self.size  # Linear Probing

        self.table[index] = (barcode, quantity)  # 빈 슬롯에 저장

    def get(self, barcode):
        """바코드에 해당하는 재고 수량 반환"""
        index = self._hash(barcode)

        while self.table[index] is not None:
            if self.table[index][0] == barcode:
                return self.table[index][1]  # 재고 수량 반환
            index = (index + 1) % self.size  # Linear Probing

        return None  # 찾지 못한 경우

    def delete(self, barcode):
        """바코드에 해당하는 상품을 삭제"""
        index = self._hash(barcode)

        while self.table[index] is not None:
            if self.table[index][0] == barcode:
                self.table[index] = None  # 삭제 후 빈 슬롯으로 설정
                return
            index = (index + 1) % self.size


# 예제 실행
ht = HashTable()
ht.insert(123456, 50)
ht.insert(789012, 30)
print(ht.get(123456))  # 50
ht.delete(123456)
print(ht.get(123456))  # None
