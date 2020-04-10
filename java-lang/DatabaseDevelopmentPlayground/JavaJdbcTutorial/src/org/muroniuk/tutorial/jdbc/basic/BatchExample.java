package org.muroniuk.tutorial.jdbc.basic;

import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Statement;

import org.myroniuk.tutorial.jdbc.ConnectionUtils;

public class BatchExample {

	public static void main(String[] args)
			throws SQLException, ClassNotFoundException {
		Connection connection = ConnectionUtils.getMyConnection();
		
		try {
			Statement stmt = connection.createStatement();
			
			connection.setAutoCommit(false);
			
			String sql1 = "UPDATE EMPLOYEE emp set emp.SALARY "
					+ "= emp.SALARY + 100 WHERE emp.DEPT_ID = 10";
			
			stmt.addBatch(sql1);
			
			String sql2 = "UPDATE EMPLOYEE emp set emp.SALARY "
					+ "= emp.SALARY + 20 WHERE emp.DEPT_ID = 20";
			
			stmt.addBatch(sql2);
			
			String sql3 = "UPDATE EMPLOYEE emp set emp.SALARY "
					+ "= emp.SALARY + 30 WHERE emp.DEPT_ID = 30";
			
			stmt.addBatch(sql3);
			
			int[] counts = stmt.executeBatch();
			
			System.out.println("Sql1 count = " + counts[0]);
			System.out.println("Sql1 count = " + counts[1]);
			System.out.println("Sql1 count = " + counts[2]);
		} catch (Exception e) {
			e.printStackTrace();
			connection.rollback();
		}
		connection.close();
	}
}
