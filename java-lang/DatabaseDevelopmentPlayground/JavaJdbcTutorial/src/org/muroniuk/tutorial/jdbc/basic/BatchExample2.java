package org.muroniuk.tutorial.jdbc.basic;

import java.sql.Connection;
import java.sql.Date;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.util.UUID;

import org.myroniuk.tutorial.jdbc.ConnectionUtils;;

public class BatchExample2 {

	public static void main(String[] main)
			throws SQLException, ClassNotFoundException {
		Connection conn = ConnectionUtils.getMyConnection();
		
		try {
			String sql = "INSERT INTO TIMEKEEPER(TIMEKEEPER_ID, DATE_TIME,"
					+ " IN_OUT, EMP_ID)"
					+ " values(?,?,?,?)";
			
			PreparedStatement stmt = conn.prepareStatement(sql);
			
			conn.setAutoCommit(false);
			
			stmt.setString(1, UUID.randomUUID().toString());
			stmt.setDate(2, new Date(System.currentTimeMillis()));
			stmt.setString(3, "I");
			stmt.setInt(4, 7839);
			
			stmt.addBatch();
			
			stmt.setString(1, UUID.randomUUID().toString());
			stmt.setDate(2, new Date(System.currentTimeMillis()));
			stmt.setString(3, "I");
			stmt.setInt(4, 7566);
			
			stmt.addBatch();

			int[] counts = stmt.executeBatch();
			
			System.out.println("counts[0] = " + counts[0]);
            System.out.println("counts[1] = " + counts[1]);
			
		} catch (Exception e) {
			e.printStackTrace();
			conn.rollback();
		}
		conn.close();
	}
}
