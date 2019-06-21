
// 4880번 다음수
// 분류: 조건 찾기
// 문제:
//      등차인지 등비인지 구하고 다음 항에 나올 수 구하기
// 풀이:
//      두 수의 차이가 같으면 등차
//      두 수의 비가 같으면 등비로 정하고
//      다음 항을 구해준다.
fun main() {
    while(true){
        val num = readLine()!!.split(" ").map { it.toInt() }
        if (num[0] == 0 && num[1] == 0 && num[2] == 0)
            break
        if(num[2]-num[1] == num[1]-num[0])
            println("AP ${num[2]+(num[1]-num[0])}")
        else
            println("GP ${num[2]*(num[1]/num[0])}")
    }
}
