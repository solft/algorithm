// 10986번 나머지 합
// 분류: 누적 합
// 문제:
//      수열의 부분합들 중 m으로 나누어 떨어지는 것의 쌍을 구하는 문제
// 풀이:
//      (Ai + ... + Aj) % m == 0 
//      (Sj - S(i-1)) % m == 0
//      Sj % m == S(i-1) % m
//      즉 부분합들 중 나머지가 같은 녀석들을 짝지어 주면 모든 쌍을 구할 수 있다.
//      추가로 나머지가 0인거랑 큰 수가 되므로 형과 나머지 신경 써주면 된다.
class Solution(val longArray: LongArray, val m: Long) {
    fun ans() {
        val modArray = LongArray(m.toInt())
        var sum = 0L
        for (element in longArray) {
            sum += element
            sum %= m
            modArray[(sum%m).toInt()]++
        }

        var ans = modArray[0]
        for (mod in modArray) {
            ans += (mod*(mod-1)) / 2
        }

        println(ans)
    }
}

fun main() {
    val (n, m) = readLine()!!.split(" ").map { it.toLong() }
    val longArray = readLine()!!.split(" ").map { it.toLong() }
    val solution = Solution(longArray.toLongArray(), m)
    solution.ans()
}