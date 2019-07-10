
// 1436번 영화감독 숌
// 분류: 브루트포스
// 문제:
//      666이 연속으로 들어간 숫자 중 작은 수부터 n번째 수를 구하라
// 풀이:
//      666부터 시작하여 1씩 늘려가며 666이 들어있는지 확인 후
//      원하는 순서가 나올 때 가지 진행한다.
fun isSix(num: Int): Boolean {
    var temp = num
    while( temp!=0 ){
        if(temp % 1000 == 666)
            return true
        temp /= 10
    }
    return false
}

fun main() {
    val n = readLine()!!.toInt()

    var ans = 666
    var count = 1

    while(true) {
        if (count == n) {
            println(ans)
            break
        }

        ans++
        if(isSix(ans))
            count++
    }
}
