set terminal gif animate delay 20 
set output "animacio.gif"
 
do for [i=1:10]{

unset key

set xrange[0:1]
set yrange[0:1]

plot "pas".i.".dat" with image
}
