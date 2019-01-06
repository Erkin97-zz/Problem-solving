func repeatedNTimes(A []int) int {
    for j := 1; j < 4; j++ {
        for i := 0; i < len(A) - j; i++ {
            if A[i] == A[i + j] {
                return A[i]
            }
        }
    }
    return 0
}