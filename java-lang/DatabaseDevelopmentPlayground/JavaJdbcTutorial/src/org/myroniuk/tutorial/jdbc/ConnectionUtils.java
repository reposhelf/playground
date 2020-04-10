package org.myroniuk.tutorial.jdbc;

import java.sql.Connection;
import java.sql.SQLException;

public class ConnectionUtils {
	
	public static Connection getMyConnection()
			throws SQLException, ClassNotFoundException {
		return MySQLConnUtils.getMySQLConnection();
	}
	
	// Test connection
	public static void main(String[] args)
			throws SQLException, ClassNotFoundException {
		System.out.println("Get connection...");
		
		Connection conn = ConnectionUtils.getMyConnection();
		System.out.println("Get connection " + conn);
		
		System.out.println("Done!");
	}
}
