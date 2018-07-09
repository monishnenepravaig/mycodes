sort #sort all lines in a file
sort -r #sort reverse order
sort -n #sort numbers
sort -n -r #sort numbers descending
sort -t$'\t' -r -n -k2 #sort tab seperated 2nd column descending
sort -t$'\t' -n -k2 #sort tab seperated 2nd column ascending
sort -t$'|' -r -n -k2 #sort | seperated 2nd column descending
