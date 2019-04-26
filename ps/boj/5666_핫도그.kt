// 5666번 핫도그
// 풀이:
//      간단한 구현 문제
//      입력 개수가 주어지지 않으므로 입력 종료 처리만 해주면 된다.
fun main() {
    while(true) {
        val a = readLine()?.split(" ")?.map { it.toDouble() } ?: break
        println("%.2f".format(a[0]/a[1]))
    }
}