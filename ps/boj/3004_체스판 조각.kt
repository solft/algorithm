// 3004번 체스판 조각
// 풀이:
//      간단한 수학 문제
fun main() {
    val n = readLine()!!.toInt()
    if(n % 2 == 0)
        println((n/2+1)*(n/2+1))
    else
        println((n/2+2)*(n/2+1))
}