
// 11179번 2진수 뒤집기
// 분류: 반복문, 구현
// 문제:
//      입력받은 십진수를 이진수로 변환하고
//      거꾸로 뒤집은 이진수를 다시 십진수로 변환하는 문제
// 풀이:
//      그대로 구현한다.
fun main() {
    var d = readLine()!!.toInt()
    var ans = 0
    val stack = mutableListOf<Int>()
    while(d > 0){
        stack.add(d%2)
        d /= 2
    }
    var bi = 1
    for (i in stack.reversed()){
        ans += bi * i
        bi *= 2
    }

    println(ans)
}
