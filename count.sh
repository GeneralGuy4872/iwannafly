#!/bin/sh
find ./*.[ch] */*.[ch] | xargs wc -l > lines_of_c.log
find ./*.(awk|pl|sh) */*.(awk|pl|sh) ./make */make | xargs wc -l > lines_of_script.log
find ./*.(xml|json|ini|[tc]sv) */*.(xml|json|ini|[tc]sv) | xargs wc -l > lines_of_plugin.log
find ./*.(hex|bin|dat|raw) */.(hex|bin|dat|raw) | xargs wc -c > bytes_of_binary.log
find ./*.(txt|html|md|man.*) */.(txt|html|md|man.*) | xargs wc -l > lines_of_doc.log
