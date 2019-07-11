#!/bin/sh
find  * -name "*.[ch]" | xargs wc -l > lines_of_c.log
find  * -name "*.awk" -o -name "*.pl" -o -name "*.sh" -o -name "make" | xargs wc -l > lines_of_script.log
find  * -name "*.xml" -o -name "*.json" -o -name "*.ini" -o -name "*.[tcd]sv" | xargs wc -l > lines_of_plugin.log
find  * -name "*.hex" -o -name "*.bin" -o -name "*.dat" -o -name "*.raw" | xargs wc -c > bytes_of_binary.log
find  * -name "*.txt" -o ! -name "*.*" -a ! -name "make" -a -type f| xargs wc -l > lines_of_text.log
find  * -name "*.md" -o -name "*.html" -o -name "*.rtf" | xargs wc -l > lines_of_markup.log
find  * -name "*.man.[0-9]" -name "README" > lines_of_docs.log
