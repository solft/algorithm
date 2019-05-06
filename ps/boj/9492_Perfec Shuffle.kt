// 9492번 Perfect Shuffle
// 분류: 구현
// 문제:
//      스트링 배열을 입력 받고 반을 나누어
//      2등분 된 배열에서 하나씩 출력하는 문제
// 풀이:
//      짝일 때는 처음부터
//      홀일 때는 반나눈 부분 부터 출력해 줬다.
fun main() {
    while(true) {
        val n = readLine()!!.toInt()
        if (n == 0)
            break

        val deck = Array(n) { readLine()!! }
        val half = (n+1)/2
        var index = 0
        while(index < n){
            if(index%2 == 0)
                println(deck[index/2])
            else
                println(deck[index/2 + half])
            index++
        }
    }
}
