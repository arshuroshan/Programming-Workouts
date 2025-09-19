class Spreadsheet:
    def __init__(self, rows: int):
        self.data = {}

    def setCell(self, cell: str, value: int) -> None:
        self.data[cell] = value

    def resetCell(self, cell: str) -> None:
        if cell in self.data:
            del self.data[cell]

    def getValue(self, formula: str) -> int:
        total = 0
        for c in formula[1:].split("+"):
            total += int(c) if c[0].isdigit() else self.data.get(c, 0)
        return total