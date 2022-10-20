"""
https://www.sqlitetutorial.net/sqlite-python/insert/
"""

import sqlite3
from sqlite3 import Error
print(sqlite3.version)

def create_connection(db):
    connection = None
    try:
        connection = sqlite3.connect(db)
    except Error as e:
        print(f"The error '{e}' occurred")
#    finally:
#        if connection:
#            connection.close()

    return connection

def create_table(conn, create_table_sql):
    """ create a table from the create_table_sql statement
    :param conn: Connection object
    :param create_table_sql: a CREATE TABLE statement
    :return:
    """
    try:
        c = conn.cursor()
        c.execute(create_table_sql)
    except Error as e:
        print(e)


#def create_project(conn, project):
#    """
#    Create a new project into the projects table
#    :param conn:
#    :param project:
#    :return: project id
#    """
#    sql = ''' INSERT INTO projects(name,begin_date,end_date)
#              VALUES(?,?,?) '''
#    cur = conn.cursor()
#    cur.execute(sql, project)
#    conn.commit()
#    return cur.lastrowid
#
#
#def create_task(conn, task):
#    """
#    Create a new task
#    :param conn:
#    :param task:
#    :return:
#    """
#
#    sql = ''' INSERT INTO tasks(name,priority,status_id,project_id,begin_date,end_date)
#              VALUES(?,?,?,?,?,?) '''
#    cur = conn.cursor()
#    cur.execute(sql, task)
#    conn.commit()
#
#    return cur.lastrowid

if __name__ == '__main__':
    # create a database connection
    db = "test.db"
    conn = create_connection(db)

    # create tables

    sql_create_projects_table = """ CREATE TABLE IF NOT EXISTS projects (
                                        id integer PRIMARY KEY,
                                        name text NOT NULL,
                                        begin_date text,
                                        end_date text
                                    ); """

    sql_create_tasks_table = """CREATE TABLE IF NOT EXISTS tasks (
                                    id integer PRIMARY KEY,
                                    name text NOT NULL,
                                    priority integer,
                                    status_id integer NOT NULL,
                                    project_id integer NOT NULL,
                                    begin_date text NOT NULL,
                                    end_date text NOT NULL,
                                    FOREIGN KEY (project_id) REFERENCES projects (id)
                                );"""
    
    if conn is not None:
        # create projects table
        create_table(conn, sql_create_projects_table)

        # create tasks table
        create_table(conn, sql_create_tasks_table)
    else:
        print("Error! cannot create the database connection.")
