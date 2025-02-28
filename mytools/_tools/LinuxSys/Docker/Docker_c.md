- `docker exec -it run-paco bash`

- `docker run -d -i -p 53682:53682 -v /home:/home -v /goinfre:/goinfre -v /sgoinfre:/sgoinfre -v /home/dinepomu/sgoinfre/francinette-image/lo    gs:/francinette/logs-t --name run-paco francinette-image /bin/bash 2>&1 | grep 'already' &> /dev/null`
  
- `docker start run-paco`
