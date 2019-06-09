// 4470번 줄번호
// 분류: 구현
// 문제:
//      스트링 입력받고 번호랑 출력하기
// 풀이:
//      입력 받고 출력하면 된다.
fun main() {
    val n = readLine()!!.toInt()
    val textArray = Array(n){ readLine()!! }
    var num = 1
    for (text in textArray){
        println("$num. $text")
        num++
    }
}
