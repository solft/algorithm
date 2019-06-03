
// 12525번 Centauri Prime (Small1)
// 12526번 Centauri Prime (Small2)
// 분류: 조건문
// 문제:
//      스트링 입력 받고 맨 뒷 문자가 모음, 자음, y 일때 따라 다른 값 출력
// 풀이:
//      문제대로 구현하면 된다.
//      Small2에서 문자열이 1자일경우 대문자로 입력되므로 이 케이스를 따져야
//      틀리지 않는다.
fun main() {
    val t = readLine()!!.toInt()
    for(i in 1 .. t){
        val country = readLine()!!
        when(country.last().toLowerCase()){
            'a', 'e', 'i', 'o', 'u' ->
                println("Case #$i: $country is ruled by a queen.")
            'y' ->
                println("Case #$i: $country is ruled by nobody.")
            else ->
                println("Case #$i: $country is ruled by a king.")
        }
    }
}
