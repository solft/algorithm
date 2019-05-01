// 1271번 엄청난 부자2
// 문제:
//      1 <= m <= n <= 10^1000일 때,
//      n/m과 n%m을 구하는 문제이다.
// 풀이:
//      BigInteger 을 사용한다.
fun main() {
    val line = readLine()!!.split(" ").map { it.toBigInteger() }
    println(line[0].div(line[1]))
    println(line[0].mod(line[1]))
}
