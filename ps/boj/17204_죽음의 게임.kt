
// 17204번 죽음의 게임
// 분류: 구현
// 문제:
//      몇 번 가리키는 방향따라 이동했을 때 원하는 번호가 나오는지 구하는 문제
// 풀이:
//      다음 인덱스따라 진행하다가 언제 원하는 숫자가 나오는지 체크한다.
//      못가는 체크를 인원수만큼 확인하고 넘어갔는데
//      싸이클 체크해도 가능할거 같다.(방문 기록 표시해서)
fun main() {
    val num = readLine()!!.split(" ").map { it.toInt() }
    val pointer = IntArray(num[0]){ readLine()!!.toInt() }

    var ans = 1
    var person = 0
    while(true){
        if(pointer[person] == num[1])
            break
        if(ans > num[0])
            break
        person = pointer[person]
        ans++
    }

    if(ans > num[0])
        println(-1)
    else
        println(ans)
}
