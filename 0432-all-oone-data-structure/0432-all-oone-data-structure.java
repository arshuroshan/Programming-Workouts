class AllOne {
    private Node root;
    private Map<String, Node> nodes;

    public AllOne() {
        root = new Node();
        root.next = root;
        root.prev = root;
        nodes = new HashMap<>();
    }

    public void inc(String key) {
        if (!nodes.containsKey(key)) {
            if (root.next == root || root.next.count > 1) {
                nodes.put(key, root.insert(new Node(key, 1)));
            } else {
                root.next.keys.add(key);
                nodes.put(key, root.next);
            }
        } else {
            Node currentNode = nodes.get(key);
            Node nextNode = currentNode.next;
            if (nextNode == root || nextNode.count > currentNode.count + 1) {
                nodes.put(key, currentNode.insert(new Node(key, currentNode.count + 1)));
            } else {
                nextNode.keys.add(key);
                nodes.put(key, nextNode);
            }
            currentNode.keys.remove(key);
            if (currentNode.keys.isEmpty()) {
                currentNode.remove();
            }
        }
    }

    public void dec(String key) {
        Node currentNode = nodes.get(key);
        if (currentNode.count == 1) {
            nodes.remove(key);
        } else {
            Node prevNode = currentNode.prev;
            if (prevNode == root || prevNode.count < currentNode.count - 1) {
                nodes.put(key, prevNode.insert(new Node(key, currentNode.count - 1)));
            } else {
                prevNode.keys.add(key);
                nodes.put(key, prevNode);
            }
        }
        currentNode.keys.remove(key);
        if (currentNode.keys.isEmpty()) {
            currentNode.remove();
        }
    }

    public String getMaxKey() {
        return root.prev.keys.isEmpty() ? "" : root.prev.keys.iterator().next();
    }

    public String getMinKey() {
        return root.next.keys.isEmpty() ? "" : root.next.keys.iterator().next();
    }
}

class Node {
    Node prev;
    Node next;
    int count;
    Set<String> keys;

    public Node() {
        this("", 0);
        keys = new HashSet<>();
    }

    public Node(String key, int count) {
        this.count = count;
        keys = new HashSet<>();
        keys.add(key);
    }

    public Node insert(Node node) {
        node.prev = this;
        node.next = this.next;
        this.next.prev = node;
        this.next = node;
        return node;
    }

    public void remove() {
        this.prev.next = this.next;
        this.next.prev = this.prev;
    }
}

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * String param_3 = obj.getMaxKey();
 * String param_4 = obj.getMinKey();
 */