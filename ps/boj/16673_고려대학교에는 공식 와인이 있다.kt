// 16673번 고려대학교에는 공식 와인이 있다
// 문제:
//      시그마 Kn+Pn^2 구하는 문제
// 풀이:
//      시그마 n = n*(n+1)/2
//      시그마 n = n*(n+1)*(2n+1)/6
fun main() {
    val num = readLine()!!.split(" ").map { it.toInt() }
    println(num[1]*num[0]*(num[0]+1)/2 + num[2]*num[0]*(num[0]+1)*(2*num[0]+1)/6)
}
