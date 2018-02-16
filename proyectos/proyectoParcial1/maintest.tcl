#!C:\cygwin64\bin\expect.exe
# For colors
proc capability cap {expr {![catch {exec tput -S << $cap}]}}
proc colorterm {} {expr {[capability setaf] && [capability setab]}}
proc tput args {exec tput -S << $args >/dev/tty}
array set color {black 0 red 1 green 2 yellow 3 blue 4 magenta 5 cyan 6 white 7}
proc foreground x {exec tput -S << "setaf $::color($x)" > /dev/tty}
proc background x {exec tput -S << "setab $::color($x)" > /dev/tty}
proc reset {} {exec tput sgr0 > /dev/tty}


#Put your test case here
eval spawn [lrange $argv 0 end]

expect "inserta texto:" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
#send "holas2<.\n"
#expect "holas." {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}



send ">>><<<Look for clothes at the <<<<<<<<<<<<<<<second floor. <<<<<<<Fresh pizza and <<<<<<<<<<<<<<<<hamburger at a shop right to <<<<<<<<<<<<<the entrance. Call <<<<<<<<<< 123<-456<-8790 <<<<<<<<<<<<<<<<to order <<<<<<<<<<<<<<<<<computers< and office<<<<<<< chairs.\n"
expect "Look for second hamburger at computer and chairs.790" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
