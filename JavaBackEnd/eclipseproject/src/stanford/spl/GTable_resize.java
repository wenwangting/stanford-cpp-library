package stanford.spl;

import acm.graphics.GObject;
import acm.util.TokenScanner;

public class GTable_resize extends JBECommand {
	public void execute(TokenScanner paramTokenScanner, JavaBackEnd paramJavaBackEnd) {
		paramTokenScanner.verifyToken("(");
		String interactorID = nextString(paramTokenScanner);
		paramTokenScanner.verifyToken(",");
		int numRows = nextInt(paramTokenScanner);
		paramTokenScanner.verifyToken(",");
		int numCols = nextInt(paramTokenScanner);
		paramTokenScanner.verifyToken(")");
		
		GObject localGObject = paramJavaBackEnd.getGObject(interactorID);
		if (localGObject != null && localGObject instanceof GTable) {
			GTable table = (GTable) localGObject;
			table.resize(numRows, numCols);
		}
	}
}
