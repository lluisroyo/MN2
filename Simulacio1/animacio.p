set terminal gif animate delay 5
set output "animacio.gif"

unset key

do for [i=1:999]{

set xrange[-1.2:1.2]
set yrange[-1.2:1.2]
set zrange[-1:1]

splot "pas".i.".dat" ls 7
}
