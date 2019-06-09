
// 15233번 Final Score
// 분류: 문자열 확인
// 문제:
//      선수명 입력 받고 승리팀을 출력하는 문제
// 풀이:
//      선수 입력 받아 set으로 만들고 입력 받은 선수가 어디에 속해있는지
//      확인 후 비교해서 결과를 출력한다.
fun main() {
    val num = readLine()!!.split(" ").map { it.toInt() }
    val A = readLine()!!.split(" ").toSet()
    val B = readLine()!!.split(" ").toSet()
    val C = readLine()!!.split(" ")
    var a = 0
    var b = 0
    for (x in C){
        if(x in A)
            a++
        else if(x in B)
            b++
    }
    if(a>b)
        println("A\n")
    else if(a<b)
        println("B\n")
    else
        println("TIE\n")
}
