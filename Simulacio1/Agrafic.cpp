set output "D:/Users/Alex Pascual/Desktop/CAMPUS VIRTUAL UAB/Metodes Numerics2/Simulacio 1/Agrafic.png"

set style line 1 lc rgb "#00e19a" lw 1 lt 1 pt 1 ps 1 # lc(line color), lw (line width), lt (line type), pt (point type), ps (point size)
set style line 2 lc rgb "#02beff" lw 1 lt 1 pt 1 ps 1 # lc(line color), lw (line width), lt (line type), pt (point type), ps (point size)
set style line 3 lc rgb "#02beff" lw 1 lt 1 pt 1 ps 1 # lc(line color), lw (line width), lt (line type), pt (point type), ps (point size)
set style fill pattern n
set key left top
f(x)=1928.586853
g(x)=487.9382136

set style fill transparent solid 0.8 noborder


set xrange[0:49999] #establim el rang de x que plotarem
set yrange[0:4500] #establim el rang de y que plotarem

set xlabel "Iteraciones" #nom de l'eix x
set ylabel "Flujo" #nom de l'eix y

plot  1928.586853 w filledcurves y1=487.9382136 lt rgb "#e2fffe" title "Zona habitable", f(x) w l ls 2 notitle, g(x) w l ls 3 notitle,  "D:/Users/Alex Pascual/Desktop/CAMPUS VIRTUAL UAB/Metodes Numerics2/Simulacio 1/habitabilidad.dat" u 1:2 w l ls 1 notitle











