// 1972번 놀라운 문자열
// 분류: 문자열, 구현, 브루트포스
// 문제:
//      D-쌍 : 문자열에서 D 거리만큼 떨어진 두 문자를 합친 문자열
//      D-쌍들 중 겹치는게 하나도 없으면 D-유일이라고 한다.
//      모든 D 값에 대해 D-유일하면 "문자열" is surprising. 출력
//      아니면 "문자열" is NOT surprising. 출력
// 풀이:
//      문자열이 길지 않기 때문에 다 검사한다.
//      D 일때마다 D쌍이 set에 있는지 검사하고 set에 없으면 넣는다
//      있으면 NOT surprising 모든 D검사를 마치면 surprising
fun main() {
    while(true){
        val str = readLine()!!

        if(str == "*")
            break

        var isSurprise = true
        for(i in 1 until str.length) {
            val check = mutableSetOf<String>()
            for(j in 0 until str.length-i) {
                if(check.contains(str[j] + str[j+i].toString())) {
                    isSurprise = false
                    break
                }
                check.add((str[j]+str[j+i].toString()))
            }
            if(!isSurprise)
                break
        }

        if(isSurprise)
            println("$str is surprising.")
        else
            println("$str is NOT surprising.")
    }
}
