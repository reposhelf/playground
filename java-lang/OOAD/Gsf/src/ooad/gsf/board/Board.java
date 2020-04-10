package ooad.gsf.board;

import java.util.ArrayList;
import java.util.List;

import ooad.gsf.unit.Unit;

public class Board {

	private int width;
	private int height;
	private List<List<Tile>> tiles;
	
	public Board(int width, int height) {
		this.width = width;
		this.height = height;
		initialize();
	}
	
	private void initialize() {
		tiles = new ArrayList<List<Tile>>();
		for (int i = 0; i != width; ++i) {
			tiles.add(new ArrayList<Tile>());
			for (int j = 0; j != height; ++j) {
				tiles.get(i).add(new Tile());
			}
		}
	}
	
	public Tile getTile(int x, int y)
			throws IndexOutOfBoundsException {
		return tiles.get(x - 1).get(y - 1);
	}
	
	public void addUnit(Unit unit, int x, int y)
			throws IndexOutOfBoundsException {
		this.getTile(x, y).addUnit(unit);
	}
	
	public void removeUnit(Unit unit, int x, int y)
			throws IndexOutOfBoundsException {
		this.getTile(x, y).removeUnit(unit);
	}
	
	public void removeUnits(int x, int y)
			throws IndexOutOfBoundsException {
		this.getTile(x, y).removeUnits();
	}
	
	public List<Unit> getUnits(int x, int y)
			throws IndexOutOfBoundsException {
		return this.getTile(x, y).getUnits();
	}
}
