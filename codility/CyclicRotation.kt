// Codility Lesson 2 CyclicRotation
fun solution(A: IntArray, K: Int): IntArray {
    val size = A.size
    // 빈 배열이 들어오는 처리 해줘야함
    if(size==0)
        return A
    val cycle = size - K % size // cycle 만큼 뒤에서 뽑아 앞으로 붙임
    val ans = IntArray(size)
    for (i in 0 until size){
        ans[i] = A[(i+cycle)%size]
    }
    return ans
}

fun main(args: Array<String>) {

}