
// 12605번 단어 뒤집기
// 분류: 구현
// 문제:
//      입력 받은 단어들의 순서를 거꾸로 해서 출력하는 문제
// 풀이:
//      적절히 입력받고 split 한 뒤에 거꾸로 출력했다.
fun main() {
    val n = readLine()!!.toInt()
    for (i in 1 .. n){
        val l = readLine()!!.split(" ")
        print("Case #$i: ")
        l.reversed().forEach{s -> print("$s ")}
        println()
    }
}
