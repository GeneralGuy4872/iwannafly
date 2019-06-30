#!/bin/sh
find ./*.[ch] */*.[ch] | xargs wc -l > lines_of_c.log
find ./*.awk */*.awk ./*.pl */*.pl ./*.sh */*.sh ./make */make | xargs wc -l > lines_of_script.log
find ./*.xml ./*.json ./*.ini ./*.[tc]sv */*.xml */*.json */*.ini */*.[tc]sv | xargs wc -l > lines_of_plugin.log
find ./*.hex ./*.bin ./*.dat ./*.raw */*.hex */*.bin */*.dat */*.raw | xargs wc -c > bytes_of_binary.log
find ./*.txt */.txt | xargs wc -l > lines_of_text.log
find ./*.md ./*.html ./*.rtf */*.md */*.html */*.rtf | xargs wc -l > lines_of_markup.log
find ./*.man.[0-9] */*.man.[0-9] > lines_of_manpage.log
