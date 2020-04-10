package org.myroniuk.simplewebapp.conn;

import java.sql.Connection;
import java.sql.SQLException;

public class ConnectionUtils {

	public static Connection getConnection()
			throws SQLException, ClassNotFoundException {
		return MySQLConnUtils.getMySQLConnection();
	}
	
	public static void closeQuietly(Connection connection) {
		try {
			connection.close();
		} catch (Exception e) {
		}
	}
	
	public static void rollbackQuietly(Connection connection) {
		try {
			connection.rollback();
		} catch (Exception e) {
		}
	}
}
