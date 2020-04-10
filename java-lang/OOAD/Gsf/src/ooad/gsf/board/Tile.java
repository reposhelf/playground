package ooad.gsf.board;

import java.util.LinkedList;
import java.util.List;

import ooad.gsf.unit.Unit;

public class Tile {

	private List<Unit> units;
	
	public Tile() {
		units = new LinkedList<Unit>();
	}
	
	protected void addUnit(Unit unit) {
		units.add(unit);
	}
	
	protected void removeUnit(Unit unit) {
		units.remove(unit);
	}
	
	protected void removeUnits() {
		units.clear();
	}
	
	protected List<Unit> getUnits() {
		return units;
	}
}
