import java.math.BigInteger
// 2547번 사탕 선생 고창영
// 분류: BigInteger
// 문제:
//         전체사탕%사람수 == 0 인지 확인하는 문제
// 풀이:
//      Java의 BigInteger 써서 쉽게 풀자
fun main() {
    val t = readLine()!!.toInt()
    repeat(t){
        readLine()
        val n = readLine()!!.toInt()
        var sum = BigInteger("0")
        for(i in 0 until n)
            sum = sum.add(readLine()!!.toBigInteger())
        if(sum.mod(n.toBigInteger()) == BigInteger("0"))
            println("YES")
        else
            println("NO")
    }
}
