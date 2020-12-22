FROM mysql:5.7

ENV MYSQL_ROOT_PASSWORD=root
ENV MYSQL_DATABASE=app_db

COPY queries.sql /docker-entrypoint-initdb.d/

EXPOSE 3306