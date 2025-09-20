import collections, bisect
from dataclasses import dataclass

@dataclass(frozen=True)
class Packet:
    source: int
    destination: int
    timestamp: int

class Router:
    def __init__(self, memoryLimit: int):
        self.memoryLimit = memoryLimit
        self.uniquePackets = set()
        self.packetQueue = collections.deque()
        self.destinationTimestamps = collections.defaultdict(list)
        self.processedPacketIndex = collections.Counter()

    def addPacket(self, source: int, destination: int, timestamp: int) -> bool:
        p = Packet(source, destination, timestamp)
        if p in self.uniquePackets:
            return False
        if len(self.packetQueue) == self.memoryLimit:
            self.forwardPacket()
        self.packetQueue.append(p)
        self.uniquePackets.add(p)
        self.destinationTimestamps[destination].append(timestamp)
        return True

    def forwardPacket(self) -> list[int]:
        if not self.packetQueue:
            return []
        p = self.packetQueue.popleft()
        self.uniquePackets.remove(p)
        self.processedPacketIndex[p.destination] += 1
        return [p.source, p.destination, p.timestamp]

    def getCount(self, destination: int, startTime: int, endTime: int) -> int:
        if destination not in self.destinationTimestamps:
            return 0
        t = self.destinationTimestamps[destination]
        s = self.processedPacketIndex.get(destination, 0)
        l = bisect.bisect_left(t, startTime, s)
        r = bisect.bisect_right(t, endTime, s)
        return r - l