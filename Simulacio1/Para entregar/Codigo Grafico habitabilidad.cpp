set output "Agrafic.png"
set title "Habitabilidad de la Tierra"
set title font ",14"
set style line 1 lc rgb "#00e19a" lw 1 lt 1 pt 1 ps 1 # lc(line color), lw (line width), lt (line type), pt (point type), ps (point size)
set style line 2 lc rgb "#02beff" lw 1 lt 1 pt 1 ps 1 # lc(line color), lw (line width), lt (line type), pt (point type), ps (point size)
set style line 3 lc rgb "#02beff" lw 1 lt 1 pt 1 ps 1 # lc(line color), lw (line width), lt (line type), pt (point type), ps (point size)
set style fill pattern n
set key left top
f(x)=1928.586853
#limites de la zona habitable
g(x)=487.9382136

set style fill transparent solid 0.8 noborder

#Aqui se deben modificar los parametros

#Rango de años
set xrange[0:30]

#Rango de Irradiancia (Consultar el final del archivo "habitabilidad.dat" para encontrar el maximo y minimo)
set yrange[0:5000]

set xlabel "Años" 
set ylabel "Irradiancia (W/m^2)" 

plot  1928.586853 w filledcurves y1=487.9382136 lt rgb "#e2fffe" title "Zona habitable", f(x) w l ls 2 notitle, g(x) w l ls 3 notitle,  "habitabilidad.dat" u 1:2 w l ls 1 notitle











