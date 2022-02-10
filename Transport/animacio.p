set terminal gif animate delay 2
set output "animacio.gif"

do for [i=0:999]{

unset key
set cbtics scale 0

set xlabel "x" font ",20"
set ylabel "y" font ",20"

set palette defined ( 0 "#000090",\
                      1 "#000fff",\
                      2 "#0090ff",\
                      3 "#0fffee",\
                      4 "#90ff70",\
                      5 "#ffee00",\
                      6 "#ff7000",\
                      7 "#ee0000",\
                      8 "#7f0000")

set xrange[0:1]
set yrange[0:1]

plot "pas".i.".dat" with image
}
