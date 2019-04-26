// 11170번 0의 개수
// 풀이:
//      N, M이 최대 7자리이므로 숫자 하나의 0의 개수 구하기 O(1)
//      총 (M-N+1)번 구하므로 O(M-N+1)
//      testcase 20번
//      총 시간 복잡도 O((M-N+1)*T)
//      그냥 단순 구현해도 시간안에 풀이 가능
fun countZero(num: Int): Int {
    var result = 0
    var temp = num
    do {
        if(temp % 10 == 0)
            result++
        temp /= 10
    }while (temp > 0)
    return result
}

fun main() {
    val t = readLine()!!.toInt()
    repeat(t){
        val n = readLine()!!.split(" ").map { it.toInt() }
        var ans = 0
        for (i in n[0] .. n[1]){
            ans += countZero(i)
        }
        println(ans)
    }
}