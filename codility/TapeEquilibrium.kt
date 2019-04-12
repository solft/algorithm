import kotlin.math.abs

// Codility Lesson 3 TapeEquilibrium
fun solution(A: IntArray): Int {
    val sumArray = IntArray(A.size)

    // 합 배열 만들기 -> 더 쉽게 만드는 방법 생각해 볼 것
    sumArray[0] = A[0]
    for(i in 1 until A.size) {
        sumArray[i] = sumArray[i-1] + A[i]
    }

    var ans = 1000000000
    // sumArray.size 로 하면 뒷부분이 빈 배열이 되므로 -1 해줘야한다.
    for(i in 0 until sumArray.size - 1){
        val potentialAns = abs(sumArray[i] + sumArray[i] - sumArray[sumArray.size - 1])
        if (potentialAns < ans){
            ans = potentialAns
        }
    }
    return ans
}

fun main(args: Array<String>) {

}