func lengthOfLastWord(s string) int {
    s = strings.TrimRight(s, " ")

    lastSpaceIndex := strings.LastIndex(s, " ")

    if lastSpaceIndex == -1 {
        return len(s)
    } else {
        return len(s) - lastSpaceIndex - 1
    }
}
