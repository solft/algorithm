
// 14681번 Quadrant Selection
// 분류: 조건문
// 문제:
//      x, y 좌표 입력 받고 몇 사분면에 있는지 출력하는 문제
// 풀이:
//      그냥 풀면 된다.
fun main() {
    val x = readLine()!!.toInt()
    val y = readLine()!!.toInt()
    if(x>0 && y>0)
        println(1)
    else if(x<0 && y>0)
        println(2)
    else if(x<0 && y<0)
        println(3)
    else if(x>0 && y<0)
        println(4)
}
