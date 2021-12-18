set terminal gif animate delay 5
set output "animacio.gif"

do for [i=1:999]{

set xrange[-1:1]
set yrange[-1:1]

plot "pas".i.".dat"
}
