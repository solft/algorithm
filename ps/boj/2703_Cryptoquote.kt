
// 2703번 Cryptoquote
// 분류: 변환
// 문제:
//      암호 규칙 주어지면 규칙에 맞게 문자 바꾸기
// 풀이:
//      주어진 알파벳만 변환하면 된다.
fun main() {
    val t = readLine()!!.toInt()
    for(i in 1 .. t){
        val str = readLine()!!
        val rule = readLine()!!

        var ans = ""
        for (c in str){
            if (c == ' ')
                ans += ' '
            else
                ans += rule[c-'A']
        }

        println(ans)
    }
}
