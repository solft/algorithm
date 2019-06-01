
// 11104번 Fridge of Your Dreams
// 분류: 이진법
// 문제:
//      이진법 입력을 십진법으로 출력
// 풀이:
//      자릿수 늘 때 마다 2씩 곱해서 1이면 더하고 0이면 넘어간다
fun main() {
    val t = readLine()!!.toInt()
    for (i in 1 .. t){
        val line = readLine()!!.toCharArray()
        var ans = 0
        var binary = 1
        for(l in line.reversed()){
            if(l == '1')
                ans += binary
            binary *= 2
        }
        println(ans)
    }
}
