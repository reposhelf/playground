package org.myroniuk.simplewebapp.conn;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class MySQLConnUtils {

	public static Connection getMySQLConnection()
			throws SQLException, ClassNotFoundException {
		String hostName = "localhost";
		String dbName = "mytest";
		String userName = "root";
		String password = "yN3jtd86rvsZ";
		
		return getMySQLConnection(hostName, dbName, userName, password);
	}
	
	public static Connection getMySQLConnection(String hostName, String dbName,
			String userName, String password)
					throws SQLException, ClassNotFoundException {
		Class.forName("org.mariadb.jdbc.Driver");
		String connectionURL = "jdbc:mysql://" + hostName + ":3306/" + dbName;
		
		return DriverManager.getConnection(connectionURL, userName, password);
	}
}
