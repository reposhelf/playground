package org.muroniuk.tutorial.jdbc.basic;

import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Statement;

import org.myroniuk.tutorial.jdbc.ConnectionUtils;

public class InsertDataExample {

	public static void main(String[] args)
			throws SQLException, ClassNotFoundException {
		Connection connection = ConnectionUtils.getMyConnection();
		
		Statement statement = connection.createStatement();
		
		String sql = "INSERT INTO SALARY_GRADE (GRADE, HIGH_SALARY, LOW_SALARY)"
				+ " VALUES(2, 20000, 10000)";
		
		int rowCount = statement.executeUpdate(sql);
		
		System.out.println("Row Count affected = " + rowCount);
	}
}
